/*****************************************************************
*
*  Licensed to the Apache Software Foundation (ASF) under one  
*  or more contributor license agreements.  See the NOTICE file
*  distributed with this work for additional information       
*  regarding copyright ownership.  The ASF licenses this file  
*  to you under the Apache License, Version 2.0 (the           
*  "License"); you may not use this file except in compliance  
*  with the License.  You may obtain a copy of the License at  
*                                                              
*    http://www.apache.org/licenses/LICENSE-2.0                
*                                                              
*  Unless required by applicable law or agreed to in writing,  
*  software distributed under the License is distributed on an 
*  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY      
*  KIND, either express or implied.  See the License for the   
*  specific language governing permissions and limitations     
*  under the License.                                          
*                                                              
*
*****************************************************************/
import { useToast } from "@chakra-ui/react";
import dayjs from "dayjs";
import relativeTime from "dayjs/plugin/relativeTime";
dayjs.extend(relativeTime);



export function showToast(title, description, type = 'info', duration = 5000, isClosable = true) {
  const toast = useToast();

  toast({
    title: title,
    description: description,
    status: type,
    duration: duration,
    isClosable: isClosable,
  });
}

export function titleCase(str) {
  return str.toLowerCase().replace(/\b\w/g, s => s.toUpperCase());
};

export function getRelativeTime(timestamp) {
  // not a Date() object
  return dayjs(timestamp).fromNow();
}

function compareVersions(a, b) {
  return a.localeCompare(b, undefined, { numeric: true, sensitivity: 'base' });
}

export function isNewerVersion(a, b) {
  return compareVersions(a, b) > 0;
}

export function getExperimentStatusFromNum(num) {
  let arr = ['CREATED',
    'VALIDATED',
    'SCHEDULED',
    'LAUNCHED',
    'EXECUTING',
    'CANCELING',
    'CANCELED',
    'COMPLETED',
    'FAILED'
  ];

  if (num < 0 || num >= arr.length) {
    return 'UNKNOWN';
  }

  return arr[num];
}


export const getColorScheme = (status) => {
  switch (status) {
    case 'COMPLETED':
      return 'green';
    case 'EXECUTING':
      return 'gray';
    case 'CREATED':
      return 'blue';
    case 'CANCELED':
      return 'yellow';
    case 'FAILED':
      return 'red';
    default:
      return 'red';
  }
};

export const getResourceFromId = (id) => {
  if (!id) return '';
  return id.split('_')[0];
};

export const truncTextToN = (str, n) => {
  return (str.length > n) ? str.substr(0, n - 1) + '...' : str;
};

export const canPerformAction = (action, status) => {
  if (action === "remove") {
    return (status !== "running" && status !== "paused");
  } else if (action === "stop") {
    return (status === "running") || (status === "paused");
  } else if (action === "start") {
    return (status === "created" || status === "exited");
  } else if (action === "pause") {
    return (status === "running");
  } else if (action === "unpause") {
    return (status === "paused");
  }
};

export const bytesToSize = (size) => {
  var i = size == 0 ? 0 : Math.floor(Math.log(size) / Math.log(1000)); return +((size / Math.pow(1000, i)).toFixed(2)) * 1 + ' ' + ['B', 'kB', 'MB', 'GB', 'TB'][i];
};

export const SAMPLE_JSON_RESPONSE = {
  "next": "https://md.cybershuttle.org/api/experiment-search/?limit=10&offset=10",
  "previous": null,
  "results": [
    {
      "experimentId": "Clone_of_Clone_of_Clone_of_NAMD_on_May_9,_2024_3:0_581f67a6-0159-44e1-9a89-09313d19d9e9",
      "projectId": "DimuthuSample_efb0b290-7664-4234-8a48-86f7176c297f",
      "gatewayId": "molecular-dynamics",
      "creationTime": 1715282078000,
      "userName": "dwannipu@iu.edu",
      "name": "Clone of Clone of Clone of NAMD on May 9, 2024 3:07 PM",
      "description": null,
      "executionId": "NAMD_dd041e87-1dde-4e57-8ec4-23af2ffa1ba0",
      "resourceHostId": "NCSADelta_e75b0d04-8b4b-417b-8ab4-da76bbd835f5",
      "experimentStatus": "COMPLETED",
      "statusUpdateTime": 1715282249038,
      "url": "https://md.cybershuttle.org/api/experiments/Clone_of_Clone_of_Clone_of_NAMD_on_May_9%2C_2024_3%3A0_581f67a6-0159-44e1-9a89-09313d19d9e9/",
      "project": "https://md.cybershuttle.org/api/projects/DimuthuSample_efb0b290-7664-4234-8a48-86f7176c297f/",
      "userHasWriteAccess": true
    },
    {
      "experimentId": "Clone_of_Clone_of_NAMD_on_May_9,_2024_3:07_PM_6b2232cc-59bf-4d6c-81a0-7574a19a98ee",
      "projectId": "DimuthuSample_efb0b290-7664-4234-8a48-86f7176c297f",
      "gatewayId": "molecular-dynamics",
      "creationTime": 1715282028000,
      "userName": "dwannipu@iu.edu",
      "name": "Clone of Clone of NAMD on May 9, 2024 3:07 PM",
      "description": null,
      "executionId": "NAMD_dd041e87-1dde-4e57-8ec4-23af2ffa1ba0",
      "resourceHostId": "NCSADelta_e75b0d04-8b4b-417b-8ab4-da76bbd835f5",
      "experimentStatus": "CREATED",
      "statusUpdateTime": 1715282028513,
      "url": "https://md.cybershuttle.org/api/experiments/Clone_of_Clone_of_NAMD_on_May_9%2C_2024_3%3A07_PM_6b2232cc-59bf-4d6c-81a0-7574a19a98ee/",
      "project": "https://md.cybershuttle.org/api/projects/DimuthuSample_efb0b290-7664-4234-8a48-86f7176c297f/",
      "userHasWriteAccess": true
    }
  ]
};
